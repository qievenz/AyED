typedef struct rNota
{
    int nota;
    struct rNota *ptrSiguiente;
};

typedef struct rEstudiante
{
    int id;
    struct rNota notas[4];
};

typedef struct rCurso
{
    int id;
    int promocionados;
    int regularizados;
    int recursantes;
};
typedef struct NodoCurso
{
    struct rCurso info;
    struct rCurso *ptrSiguiente;
};