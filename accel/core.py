

def vector_sub(vector_a, vector_b):
    return [
        element_a - element_b
        for element_a, element_b in zip(vector_a, vector_b)
    ]