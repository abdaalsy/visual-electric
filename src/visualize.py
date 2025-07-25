from pathlib import Path

import manim
import os
import numpy as np


class Visualize(manim.Scene):
    def construct(self):
        square = manim.Square()
        circle = manim.Circle()
        self.play(manim.Create(square))
        self.play(manim.Transform(square, circle))
        self.play(manim.FadeOut(square))

    @staticmethod
    def fetch_positions(path: Path):
        if (not (os.path.exists(path) and path.suffix==".npy")):
            return None
        positions = np.load(path)
        return positions