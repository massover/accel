import accel


def test_vector_sub():
    vector = accel.vector_sub([5, 4, 3, 2, 1], [1, 1, 1, 1, 1])
    assert vector == [4, 3, 2, 1, 0]
