# The plan
1. Pass a problem to an LLM which will extract the key details and put it in some format.
    - Running locally cus I am NOT paying shit.
        - Use gguf + ollama for quick setup and fast inference (speed will be important when I move to cloud hardware).
    - Possible choices (given by GPT): LLaMA 3 8B, Mistral 7B, Mixtral 8x7B, OpenHermes 2.5, Nous-Hermes 2 Mistral
    - AI should return a JSON string including for each object in the scene:
        - Position
        - length, width, height (if 3D)
        - Initial velocity vector
        - Initial acceleration vector
        - Mass
        - Charge
        - If the object in question is fixed.


2. Do all the maths and stuff to determine the dynamics of the scene.

3. Pass that info to manim, outputting an mp4 file

4. Display ts to the user (maybe on the web)