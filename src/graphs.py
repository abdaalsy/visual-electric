import matplotlib.pyplot as plt
import numpy as np
from datetime import datetime
from os import makedirs

# shape of positions: (numTimesteps, numCharges, 2)

def posToDisplacements(positions):
    # Displacements will be scalar, since we only really care about magnitude for this plot
    displacements = np.zeros(shape=(positions.shape[0], positions.shape[1]), dtype=np.float32)
    displacements += np.linalg.norm(positions, axis=2)
    displacements -= displacements[0] # offsetting displacement magnitudes so that they all start at zero on the first timestep
    displacements = np.swapaxes(displacements, 1, 0)    # permuting so that displacement is num charges long and each element is an array of displacements for each timestep
    for l in range(len(displacements)):
        for i in range(len(displacements[l])):
            displacements[l, i] = displacements[l, 0:i+1].sum()
    return displacements

def displacementsGraph(charges: np.typing.NDArray[np.float32], positions, times) -> None:
    """
    charges is just an array of doubles. But positions is an array of each charge's position at each time step.
    On the plot, each curve will be labelled in the format <charge> @ (x, y) where (x, y) is the initial position.
    """
    displacements = posToDisplacements(positions)

    print("Positions:")
    print(positions)
    print("\nTimes")
    print(times)
    print("\nDisplacements:")
    print(displacements)
    
    plotAll = lambda array, charges: [plt.plot(times, array[i], label=f"{charges[i]} C @ {f'({positions[0, i][0]}, {positions[0, i][1]})'}") for i in range(len(charges))]
    plotAll(displacements, charges)
    plt.title("Displacements of Charges")
    plt.xlabel("Time (s)")
    plt.ylabel("Displacement (m)")
    plt.legend()
    makedirs("plots", exist_ok=True)
    plt.savefig(f"plots/plot_{datetime.now().strftime('%Y-%m-%d_%H;%M;%S')}.png")
    plt.show()

# test inputs (COMMENT OUT BEFORE USE)
times = np.linspace(0, 10, 5, dtype=np.float32)
positions = np.random.randint(0, 50, size=(5, 3, 2))
displacementsGraph(np.array([1, 2, 3], dtype=np.float32), positions, times)