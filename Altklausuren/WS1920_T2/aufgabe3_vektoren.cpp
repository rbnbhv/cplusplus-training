// deleteMatch(int i)
// fehlende Operator und fehlende Methode hinzufügen (push_back) und resize(), [] operator

int& operator[] (unsigned idx) {
    return vec[idx];
}

const int& operator[] (unsigned idx) const {
    return vec[idx];
}

void push_back(int elem) {
    if (m_N >= m_S) {
        resize()
    }
    m_pField[m_N++] = elem;
}

private:
void resize() {
    const unsigned newSize = (m_W == 0) ? m_S * 2 ? m_W + m_S;
    int newField* = new int[newSize];
    for (unsigned i = 0; i < newSize; ++i) {
        newField[i] = m_pField[i];
    }
    delete m_pField;
    m_S = newSize;
    m_pField = newField;
    newField = nullptr;
}

void deleteMatch(int i) {
    for (unsigned j = 0, idx = 0; j < m_N; ++j) {
        if (i != m_pField[j]) {
            m_pField[idx++] = m_pField[j];
        }
    }
    m_N = idx;
}
