import React from "react";

const TabelaHead = (props) => (
    <thead>
      <tr>
        <th colSpan="5">Tabela de filmes</th>
      </tr>
      <tr>
        <th>Título          
          <div className='container-setinhas'>
            <div onClick={() => props.ordenarCrescente()}>&#129093;</div>
            <div onClick={() => props.ordenarDecrescente()}>&#129095;</div>
          </div>
        </th>
        <th>Diretor</th>
        <th>Gênero</th>
        <th>Ano</th>
        <th></th>
      </tr>
    </thead>
  );

export default TabelaHead;
