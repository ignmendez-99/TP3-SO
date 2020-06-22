#ifndef NEW_SERVER_H
#define NEW_SERVER_H

#define NUMBER_OF_CHALLENGES 11

char * hints [NUMBER_OF_CHALLENGES] = {
                                    "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\nAdemás, deberán implementar otro programa para comunicarse conmigo.\n\nDeberán estar atentos a los easter eggs.\n\nPara verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'",
                                    "HASHTAG left up up left down right down left ASTERISK",
                                    "https://voca.ro/hcmH7cqyqTg",
                                    "EBADF...",
                                    "respuesta = strings:377",
                                    ".data ? .bss .comment .shstrtab .symtab .strtab",
                                    "mixed fds",
                                    "Logo",
                                    "Tango Hotel India Sierra India Sierra Alfa Whiskey Echo Sierra Oscar Mike Echo",
                                    "quine",
                                    "b gdbme y encontrá el valor mágico"
                                    };

char * questions [NUMBER_OF_CHALLENGES] = {
                                        "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?",
                                        "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?", 
                                        "¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?", 
                                        "¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?", 
                                        "¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?", 
                                        "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?", 
                                        "¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?", 
                                        "¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?", 
                                        "sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?",
                                        "¿Cuáles son las características del protocolo SCTP?",
                                        "¿Qué es un RFC?"
                                        };


char * answers [NUMBER_OF_CHALLENGES] = {
                                    "f959505ee0c9d7fb7d81a0904aa4e9f4", 
                                    "d91e99f014daecaf327fc8b96041aa34", 
                                    "37df469bcb37ed7e83bbd42a8bae9200", 
                                    "b666036f3c79608d3e9195292e3466c9", 
                                    "ce0c1111d26e426e0ea7c1f58d5488fe", 
                                    "752435d46843b72130c3b0b3bc1220d4", 
                                    "80894072aa67d91345425181c937414f", 
                                    "1a48d44bf33b852e4324cac671bab804", 
                                    "88d0feeef1abd8898dcf7915e2de6b44", 
                                    "c2fb1566098f29ce6b5048fcd6aad77c", 
                                    "d6159d8c323a7102f9b0a8741513e65b"
                                    };


#endif