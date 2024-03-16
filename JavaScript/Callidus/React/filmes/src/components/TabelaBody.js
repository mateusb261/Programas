import React from "react";

const TabelaBody = (props) => (
  <tbody>
    {props.filmes.map((filme, index) => (
      <tr key={filme.titulo}>
        <td>{filme.titulo}</td>
        <td>{filme.diretor}</td>
        <td>{filme.genero}</td>
        <td>{filme.ano}</td>
        <td>
          <button
            className="botao remover"
            onClick={() => props.removerLinha(filme.titulo)}
            id={filme.titulo}
          >
            Remover
          </button>
        </td>
      </tr>
    ))}
  </tbody>
);

export default TabelaBody;
