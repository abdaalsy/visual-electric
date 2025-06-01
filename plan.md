1. Pass a problem to an LLM which will extract the key details and put it in some format.
    Running locally cus I am NOT paying shit.
        Use gguf + 0llama for quick setup and fast inference. (speed will be important when I move to cloud hardware).
    Possible choices (given by GPT): LLaMA 3 8B, Mistral 7B, Mixtral 8x7B, OpenHermes 2.5, Nous-Hermes 2 Mistral
    Extract into JSON (?) format
        Each object could be something in the problem (ie. point charge, field origin, charged object)
        Given values provided for each object.
        Describe the goal in a way that my program can understand.

2. Do all the maths and stuff to determine the dynamics of the scene.
    The problems that I'll be doing aren't gonna be that complicated. They mostly boil down to a similar few things
        Using the given information to get charges, mass, initial positions, velocities, accelerations, and the presence of fields.
        sampling positions of particles in an electric field.
        I can create functions that take in the required data and solve
        Lets not forget though that the goal isn't to get an answer, but to model the problem, we are only solving for positions
        


3. Pass that info to manim, outputting an mp4 file

4. Display ts to the user (maybe on the web)