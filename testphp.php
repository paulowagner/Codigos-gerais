<!DOCTYPE html>
<html lang = "pt-br">
  <head>
	<meta charset="utf-8">
  	<link rel="estilo" href="estilo.css" />
    <title>Aprendendo!!</title>
  </head>
	<body>
	 <h1>Languages you can learn on Codecademy:</h1>
        <p>
          <?php

          		$cond = 1;
			    while($cond < 4){
			        echo "teste ";
			        $cond ++;
			    }
			    echo '<br />';
				if(date('m')==1)
					echo "Janeiro";
				elseif(date('m')==2)
					echo "Fevereiro";
				elseif(date('m')==3)
					echo "Março";
				elseif(date('m')==4)
					echo "Abril";
				elseif(date('m')==5)
					echo "Maio";
				elseif(date('m')==6)
					echo "Junho";
				elseif(date('m')==7)
					echo "Julio";
				elseif(date('m')==8)
					echo "Agosto";
				elseif(date('m')==9)
					echo "Setembro";
				elseif(date('m')==10)
					echo "Outubro";
				elseif(date('m')==11)
					echo "Novembro";
				else
					echo "Dezembro";
				echo '<br />';
		            	echo " Hoje eh dia " . date('m');
				echo '<br />';
				echo " Agora sao " . date('H:i:s');
				echo '<br />';
				for ($leap = 2004; $leap < 2050; $leap = $leap + 4) {
       				echo "<p>$leap</p>";
      			}
      			$array = array();
			    array_push($array,"Paulo");
			    array_push($array,"Joelma");
			    array_push($array,"Juliana");
			    array_push($array,"Ana Paula");
			    array_push($array,"Wallace");
			    array_push($array,"Matheus");
			    array_push($array,"Vitor");
			    array_push($array,"Luan");
				// Ordene a lista
			    sort($array);
				// Escolha um vencedor de forma aleatória!
			    $rand = rand(0,count($array)-1);
				// Imprima o nome do vencedor em LETRAS MAIÚSCULAS
				print strtoupper($array[$rand]);
				echo '<br />';
				
				
				// O código abaixo cria a classe
		        class Person {
		            // Criando algumas propriedades (variáveis ligadas a um objeto)
		            public $isAlive = true;
		            public $firstname;
		            public $lastname;
		            public $age;
		            
		            // Atribuindo os valores
		            public function __construct($firstname, $lastname, $age) {
		              $this->firstname = $firstname;
		              $this->lastname = $lastname;
		              $this->age = $age;
		            }
		            
		            // Criando um método (função ligada a um objeto)
		            public function greet() {
		              return "<ul>Ola, meu nome eh ,</ul>" . $this->firstname . " " . $this->lastname . ". Eh um prazer conhece-lo! :-)";
		            }
		          }
		          
		        // Criando uma nova pessoa chamada "entediado 12345", que tem 12345 anos de idade ;-)
		        $me = new Person('Paulo', 'Wagner', 23);
        		if (is_a($me, "Person")) {
		          echo "Sou uma pessoa, ";
		        }
		        if (property_exists($me, "firstname")) {
		          echo "tenho um nome, ";
		        }
		        if (method_exists($me, "greet")) {
		          echo "e sei dançar!";
		        }
        		// Imprime o retorno do método greet
        		echo $me->greet(); 

          ?>
        </p>
        <a href="hj.php">Clique aqui!!</a>
	</body>
</html>
