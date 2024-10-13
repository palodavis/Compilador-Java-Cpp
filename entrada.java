class Pessoa {
    int i = 1;
    int a = 2;
    int b = 5;
    String nome = 'Paulo';
    float num = 28.1;
    double num = 20.00;
    char op = 's';
    boolean ativo = true;
    double resultado = 0.0;

    if (i > 10) {
        System.out.println("Maior que 10");
    }

    else if (i < 10) {
        System.out.println("Menor que 10");
    }

    else {
        System.out.println("Teste else");
    }

    while (i < 10) {
        System.out.println("Teste while");
    }

    System.out.println("Programa finalizado");

    int x = (a > 10) ? 1 : 0;
    int y = ((a > 0) ? "Positivo":"Negativo");

}