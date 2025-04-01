#include "sistema.h"

int main() {
  string nomeApp = "Sistema de Reservas";
  App app(nomeApp);

  // Cadastro de usuários
  string nomeAnfitriao = "Fulano", telefoneAnfitriao = "1234-5678",
         cepAnfitriao = "12345-000", cnpjAnfitriao = "12.345.678/0001-99";
  Anfitriao anfitriao(nomeAnfitriao, telefoneAnfitriao, cepAnfitriao,
                      cnpjAnfitriao);

  string nomeHospede = "Ciclano", telefoneHospede = "8765-4321",
         cepHospede = "54321-000", cpfHospede = "123.456.789-00";
  int idadeHospede = 30;
  Hospede hospede(nomeHospede, telefoneHospede, cepHospede, cpfHospede,
                  idadeHospede);

  app.cadastrarUsuario(&anfitriao);
  app.cadastrarUsuario(&hospede);

  // Cadastro de imóvel
  string enderecoCasa = "Rua A, 123", cepCasa = "12345-000";
  double tamanhoCasa = 120.0, precoPorDiaCasa = 300.0;
  int moveisCasa = 5, comodosCasa = 2, capacidadeCasa = 6;

  Casa casa(enderecoCasa, tamanhoCasa, moveisCasa, comodosCasa, cepCasa,
            capacidadeCasa, precoPorDiaCasa, &anfitriao);
  app.cadastrarImovel(&casa);

  // Listar imóveis
  app.listarImoveis();

  // Criar e registrar reserva
  string dataReserva = "2025-04-10";
  Reserva reserva(precoPorDiaCasa, &hospede, &casa, dataReserva);
  app.cadastrarReserva(reserva);

  // Listar reservas
  app.listarReservas();

  // Avaliação da reserva
  reserva.avaliar(5);

  return 0;
}
