import React from "react";

const TabelaFoot = (props) => (
    <tfoot>
      <tr>
        <td colSpan="5">Quantidade de filmes na tabela: {props.qdeFilmes}</td>
      </tr>
    </tfoot>
  );


export default TabelaFoot;
