import threading
import time

# Variáveis globais
estoque = 100

# Criação do objeto Lock para sincronização
lock = threading.Lock()

def atendente(id_atendente):
    """
    Função que representa o trabalho de um atendente.
    Cada atendente tentará realizar 10 vendas.
    """
    global estoque
    
    for i in range(10):
        # A instrução 'with' adquire o lock automaticamente ao entrar no bloco
        # e o libera (release) automaticamente ao sair, mesmo se ocorrer um erro.
        with lock:
            # --- INÍCIO DA REGIÃO CRÍTICA ---
            # Apenas uma thread por vez pode executar o código dentro deste bloco.
            
            # 1. LER: A thread lê o valor atual do estoque
            estoque_atual = estoque
            
            # 2. PAUSAR: Simulamos o tempo de processamento. 
            # Mesmo com o sleep forçando a troca de contexto, outras threads 
            # NÃO conseguirão acessar a região crítica porque o Lock está ativo.
            time.sleep(0.01)
            
            # 3. MODIFICAR/ESCREVER: A thread calcula e salva o novo valor
            estoque = estoque_atual - 1
            
            # --- FIM DA REGIÃO CRÍTICA ---
        
        # O print está fora da região crítica para não prender o Lock 
        # mais tempo do que o estritamente necessário para operações em memória.
        print(f"Atendente {id_atendente} vendeu 1 item. (Estoque na visão dele após a venda: {estoque})")

# Lista para armazenar as threads criadas
threads = []

print(f"--- INICIANDO AS VENDAS COM LOCK (Estoque inicial: {estoque}) ---\n")

# Criação e inicialização das 5 threads (5 atendentes)
for i in range(5):
    t = threading.Thread(target=atendente, args=(i + 1,))
    threads.append(t)
    t.start()

# Aguarda todas as threads terminarem suas execuções
for t in threads:
    t.join()

print("\n--- VENDAS ENCERRADAS ---")

# O estoque final esperado: 100 - (5 atendentes * 10 vendas) = 50.
# Com o uso do Lock, o valor real será sempre idêntico ao esperado.
estoque_esperado = 100 - (5 * 10)
print(f"Estoque final esperado : {estoque_esperado}")
print(f"Estoque final real     : {estoque}")
