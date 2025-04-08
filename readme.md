# Modelagem do problema de __"Distribuição de Carga em Avião"__

Este projeto foi feito para retornar o modelo, em __programação linear__, de uma solução para a instância do problema de __distribuição de carga em avião__ dada pelo usuário.

O formato de entrada e o problema modelado estão descritos nas próximas seções.

## Problema modelado: distribuição de Carga em Avião
Um avião de carga tem __k compartimentos__, numerados de 1 a k, para armazenar sua carga. Cada um destes compartimentos tem limites de __peso__ e __espaço__ ocupado, dados pelos valores wi (em toneladas) e vi (em m³), respectivamente, para i = 1, 2, ..., k.

Além disso, o __peso__ colocado em cada compartimento deve ter a mesma __proporção__ em relação ao __peso máximo suportado__ pelo compartimento - por exemplo, se o compartimento 1 está utilizando 80% do peso máximo suportado por ele, todos os outros compartimentos devem estar, também, utilizando 80% de seu peso máximo.

Temos __n carregamentos__ para embarcar no avião, numerados de 1 a n, cada um com __peso__, __volume__ e __ganho por tonelada transportada__, dados pelos valores pj (em toneladas), tj (em m³) e gj (em reais/tonelada), para j = 1, 2, ..., n.

É possível carregar parte de cada um dos carregamentos. Ou seja, __qualquer proporção dos carregamentos pode ser aceita__.

O objetivo é determinar quanto de cada carregamento deve ser aceito e como distribuir pelos compartimentos de forma a __maximizar o ganho total__.

## Formato de entrada para o programa
A entrada começa com __dois números__, k e n, indicando a __quantidade de compartimentos e carregamentos__, respectivamente. 

Depois, são inseridas __k linhas__, cada uma com os __dados de um compartimento__. Cada compartimento é descrito com __dois números__ indicando as capacidades de peso e volume, wi e vi, com i = 1, 2, ..., k. 

Por último, temos __n linhas__, cada uma com os __dados de um carregamento__. Cada carregamento é descrito com __três números__ indicando o peso, o volume e o ganho por tonelada transportada, pj, tj e gj, com j = 1, 2, ..., n.