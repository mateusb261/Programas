public void saveAutorToFile(Autor autor) {
    try (PrintWriter writer = new PrintWriter(new FileWriter(AUTORES_EDITORAS, true))) {

      if (contador_autores == 0) {
        writer.println("Autores da editora " + nome + ":");
      }

      if (autoresEditora.isEmpty() && contador_autores > 0) {
        writer.println("");
        writer.println("");
        writer.println("Autores da editora " + nome + ":");
      }

      writer.println(autor.getNome());

      contador_autores++;

    } catch (IOException e) {
      System.err.println("Erro ao escrever no arquivo: " + e.getMessage());
    }
  }

@Override
    public void adicionarLivroParaAutor(int idAutor, Livro livro) {
        Autor autor = buscarAutorPorId(idAutor);
        if (autor != null) {
            autor.adicionarLivro(livro);
            livro.saveLivroToFile(); // Salva o livro no arquivo de texto
        } else {
            System.out.println("Autor não encontrado. Livro não adicionado.");
        }
    }


    Autor mateus = new Autor("Mateus", "Bras");
        Editora saraiva = new Editora("Saraiva", "Bras");
        Livro teste1 = new Livro("teste1", mateus, saraiva);

        saraiva.saveAutorToFile(mateus);
        saraiva.saveLivroToFile(teste1);

        mateus.saveLivroToFile(teste1);

        Autor marcos = new Autor("Marcos", "Bras");
        Editora moderna = new Editora("Moderna", "Bras");
        Livro teste2 = new Livro("teste2", marcos, moderna);

        moderna.saveAutorToFile(marcos);
        moderna.saveLivroToFile(teste2);

        marcos.saveLivroToFile(teste2);