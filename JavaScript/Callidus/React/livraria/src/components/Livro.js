import React from "react";
import { useParams } from "react-router-dom";
import NotFound from "./NotFound";

const Livro = ({ livros }) => {
  const { livroSlug } = useParams();
  console.log("livroSlug:", livroSlug);

  const livro = livros.find((livro) => livro.slug === livroSlug);
  console.log("livro:", livro);

  if (!livro) {
    return <NotFound />;
  }

  return (
    <main className="principal">
      <div className="pag-livro">
        <h2>{livro.titulo}</h2>
        <div className="livro">
          <img
            src={`/imagens/capas/${livro.id}.jpg`}
            alt={`Thumbnail da capa do livro ${livro.titulo}`}
          />
          <ul>
            <li>ISBN: {livro.isbn}</li>
            <li>Autor: {livro.autor}</li>
            <li>Ano: {livro.ano}</li>
            <li>Páginas: {livro.paginas}</li>
            <li>Preço: R${livro.preco},00</li>
          </ul>
          <hr />
          <h3>Descrição do livro</h3>
          <p>{livro.descricao}</p>
        </div>
      </div>
    </main>
  );
};

export default Livro;
