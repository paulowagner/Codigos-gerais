#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <sstream>
#include <vector>
#include <limits>

typedef long long int ll;

using namespace std;

const double INFINITO = numeric_limits<double>::infinity();

class Vertice
{
	public:
		class Aresta
				{
					private:
						Vertice* inicio;
						Vertice* fim;
						double   custo;
					public:
						Aresta(Vertice* inicio, Vertice* fim, double custo=0){
							this->setInicio(inicio);
							this->setFim(fim);
							this->setCusto(custo);
						}

						friend ostream &operator<<( ostream &output, Aresta &A )
						{
							output << "Inicio : " << (*A.getInicio()) << " Fim : " << (*A.getFim()) << " Custo : "<< A.getCusto() ;
							return output;
						}

						bool operator<( Aresta &A ){
							
							return (this->custo < A.getCusto());

						}

						bool operator<=( Aresta &A ){
							
							return (this->custo <= A.getCusto());

						}

						bool operator>( Aresta &A ){
							
							return (this->custo > A.getCusto());

						}

						bool operator>=( Aresta &A ){
							
							return (this->custo >= A.getCusto());

						}

						bool operator==( Aresta &A ){
							
							return (this->custo == A.getCusto());

						}

						Vertice* getInicio(){
							return this->inicio;
						}

						Vertice* getFim(){
							return this->fim;
						}

						double getCusto(){
							return this->custo;
						}

						void setInicio( Vertice* inicio ){
							this->inicio = inicio;
						}

						void setFim( Vertice* fim ){
							this->fim = fim;
						}

						void setCusto( double custo ){
							this->custo = custo;
						}
						
					
				};



		
		Vertice(string nome){
			this->setNome(nome);
			this->setVisitado();
		}

		friend ostream &operator<<( ostream &output, Vertice &V )
		{
			output << V.getNome();
			return output;
		}

		string getNome(){
			return this->nome;
		}

		bool foiVisitado(){
			return this->visitado;
		}

		list<Aresta*> getListaAdj(){
			return this->listaAdj;
		}

		void setNome(string nome){
			this->nome = nome;
		}

		void setVisitado(bool visitado=false){
			this->visitado = visitado;
		}

		void addAresta(Vertice* fim, double custo=0){

			Aresta* aux = new Aresta(this, fim, custo);

			listaAdj.push_back(aux);

		}

		string imprimeListaAdj(){
			string lista = "";
			for(list<Aresta*>::iterator it = this->listaAdj.begin(); it!=this->listaAdj.end(); it++){

				 cout<< **it << endl;

			}

			return lista;

		}
		list<Aresta*> listaAdj;


	private:
		string nome;
		bool visitado;
		

};

class Grafo{
	private:
		ll numVertices;
		map<string,Vertice*> vertices;

	public:
		Grafo(){
			this->numVertices = 0;
		}

		ll getNumVertices(){
			return this->numVertices;
		}

		map<string,Vertice*> getVertices(){
			return this->vertices;
		}

		void setNumVertices(ll num){

			this->numVertices = num;
		}

		void addVertice(string nome){

			this->vertices[nome] = new Vertice(nome);
			this->numVertices = this->getNumVertices()+1;

		}

		void addVertice(long double nome){

			this->vertices[this->numToString(nome)] = new Vertice(this->numToString(nome));
			this->numVertices = this->getNumVertices()+1;

		}

		friend ostream &operator<<( ostream &output, Grafo &G )
		{
			output << G.getNumVertices();
			return output;
		}

		void imprimeVertices(){

			for(map<string,Vertice*>::iterator it = this->vertices.begin(); it!=this->vertices.end(); it++){

				 cout<< (*(it->second)) << endl;

			}

		}

		void addAresta(string origem, string destino, long double custo){

			this->getVertices()[origem]->addAresta( this->getVertices()[destino], custo );

		}

		void addAresta(long double origem, long double destino, long double custo){

			this->getVertices()[ this->numToString(origem) ]->addAresta( this->getVertices()[ this->numToString(destino) ], custo );

		}


		static string numToString(long double num){
			stringstream ss;
			ss << num;
			return ss.str();
		}

		static long double stringToNum(string num){
			stringstream ss;
			ss << num;
			long double aux;
			ss >> aux;
			return aux;
		}

		void iniciaCaminhoDist( map<string,string> &caminho, map<string,long double> &distancia, string origem ){

			for( map<string, Vertice*>::iterator it = this->vertices.begin() ; it!= this->vertices.end() ; it++ ){
				caminho[it->first] = "";
				distancia[it->first] = INFINITO;
			}

			distancia[origem] = 0;

		}


		void removeDistanciaAntiga( multimap<long double, string> &fila, list<Vertice::Aresta*>::iterator it, string origem, map<string,long double> &distancia ){

			multimap<long double, string>::iterator aux = fila.find( distancia[(*it)->getFim()->getNome()] );
			if( aux == fila.end() ) return;
			while(aux->second != (*it)->getFim()->getNome()){
				aux++;
			}

			
			fila.erase(aux);
		}

		void atualizaCaminhos(map<string,string> &caminho, map<string,long double> &distancia, multimap<long double, string> &fila , string origem){


			for(list<Vertice::Aresta*>::iterator it = this->vertices[origem]->listaAdj.begin() ; it!=this->vertices[origem]->listaAdj.end(); it++ ){
				
				if( distancia[origem]+(*it)->getCusto() < distancia[(*it)->getFim()->getNome()] ){

					this->removeDistanciaAntiga( fila, it, origem, distancia );

					distancia[(*it)->getFim()->getNome()] = distancia[origem]+(*it)->getCusto();
					caminho[(*it)->getFim()->getNome()] = origem;
					fila.insert( pair<long double, string>( distancia[(*it)->getFim()->getNome()], (*it)->getFim()->getNome() ) );

				}

			}

		}

		void dijkstra(string origem, map<string,string> &caminho, map<string,long double> &distancia){
			
			multimap<long double, string> fila;


			iniciaCaminhoDist( caminho, distancia, origem );


			fila.insert( pair<long double, string>( distancia[origem], origem ) );

			while( !fila.empty() ){

				string nomeMenorDist = fila.begin()->second;
				fila.erase(fila.begin());
				this->atualizaCaminhos(caminho, distancia, fila, nomeMenorDist);

			}


		}

};

				


int main(){

	Grafo novo;
	map<string,string> caminho;
	map<string,long double> distancia;

	novo.addVertice("1");
	novo.addVertice("2");
	novo.addVertice("3");
	novo.addVertice("4");
	novo.addVertice("5");
	novo.addVertice("6");

	novo.addAresta("1", "2", 7);
	novo.addAresta("1", "3", 9);
	novo.addAresta("1", "6", 14);
	novo.addAresta("2", "1", 7);
	novo.addAresta("2", "3", 10);
	novo.addAresta("2", "4", 15);
	novo.addAresta("6", "1", 14);
	novo.addAresta("6", "3", 2);
	novo.addAresta("6", "5", 9);
	novo.addAresta("3", "1", 9);
	novo.addAresta("3", "6", 2);
	novo.addAresta("3", "2", 10);
	novo.addAresta("3", "4", 11);
	novo.addAresta("5", "6", 9);
	novo.addAresta("5", "4", 6);
	novo.addAresta("4", "5", 6);
	novo.addAresta("4", "3", 11);
	novo.addAresta("4", "2", 15);

	

	novo.dijkstra("1",caminho,distancia);

	for( map<string,long double>::iterator it = distancia.begin(); it!= distancia.end(); it++ ){

		cout<< "NOME: "<<it->first;
		cout<< " => MIN DIST: "<<it->second<<endl;

	}

}