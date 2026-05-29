import threading
import time

# Variável global compartilhada entre todas as threads
estoque = 100

def atendente(id_atendente):
    """
    Função que representa o trabalho de um atendente.
    Cada atendente tentará realizar 10 vendas.
    """
    global estoque
    
    for i in range(10):
        # 1. LER: A thread lê o valor atual do estoque
        estoque_atual = estoque
        
        # 2. PAUSAR: O sleep simula um tempo de processamento e força 
        # a troca de contexto pelo Sistema Operacional. Isso aumenta 
        # drasticamente a chance da condição de corrida ocorrer.
        time.sleep(0.01)
        
        # 3. MODIFICAR/ESCREVER: A thread calcula o novo valor e o salva
        estoque = estoque_atual - 1
        
        # Imprime a venda realizada
        print(f"Atendente {id_atendente} vendeu 1 item. (Estoque na visão dele: {estoque})")

# Lista para armazenar as threads criadas
threads = []

print(f"--- INICIANDO AS VENDAS (Estoque inicial: {estoque}) ---\n")

# Criação e inicialização das 5 threads (5 atendentes)
for i in range(5):
    # Passamos o número do atendente (i+1) como argumento para a função
    t = threading.Thread(target=atendente, args=(i + 1,))
    threads.append(t)
    t.start()

# Aguarda todas as threads terminarem suas execuções antes de prosseguir
for t in threads:
    t.join()

print("\n--- VENDAS ENCERRADAS ---")

# O estoque final esperado seria 100 - (5 atendentes * 10 vendas) = 50.
# Porém, devido à condição de corrida, o valor real será quase sempre diferente de 50.
estoque_esperado = 100 - (5 * 10)
print(f"Estoque final esperado : {estoque_esperado}")
print(f"Estoque final real     : {estoque}")
