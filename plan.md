# The plan
1. Pass a problem to an LLM which will extract the key details and put it in some format.
    - Running locally cus I am NOT paying shit.
        - Use gguf + ollama for quick setup and fast inference (speed will be important when I move to cloud hardware).
    - Possible choices (given by GPT): LLaMA 3 8B, Mistral 7B, Mixtral 8x7B, OpenHermes 2.5, Nous-Hermes 2 Mistral
    - AI should return a JSON string including for each object in the scene:
        - Position vector
        - velocity vector
        - acceleration vector
        - Mass
        - Charge

2. Do all the maths and stuff to determine the dynamics of the scene.
    - for 1.0, we are only concerned about the dynamics of any number of point charges.
    - use the bounding vectors to create a new scene space with a data point every deltaX metres.
        - scene space has only integer coordinates starting from the top left.
        - store positions in this scene space.
    - At each timestep,
        - compute electric field at each point in scene space by summing up the individual electric fields caused by each point
            - adjust for difference in unit magnitude of scene space to real space
        - compute new acceleration from electric field, charge, and mass
        - compute new velocity and position using new acceleration, and previous velocity, position, and time.
            - adjust for difference in unit magnitude of scene space to real space
        - store new position in scene space.

3. Pass that info to manim, outputting an mp4 file
    - paint positive charges blue with a white plus, and negative charges red with a white minus (3b1b style)
    - vector E field.

4. Display ts to the user (maybe on the web someday)
