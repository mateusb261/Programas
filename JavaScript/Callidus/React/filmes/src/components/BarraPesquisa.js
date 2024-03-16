import React, {useState} from "react";


function BarraPesquisa(props){
  const [inputValue, setInputValue] = useState('');

  const handleInputChange = (event) => {
    setInputValue(event.target.value);
  };

  return (
    <div>
      <input type="text" className="barra-pesquisa" value={inputValue} onChange={handleInputChange}></input>
      <button
      className="botao remover"
      onClick={() => props.pesquisa(inputValue)}
      >
        Pesquisar
      </button>
      </div>

  )
};


export default BarraPesquisa;
