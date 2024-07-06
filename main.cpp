#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>

struct Producto {
    int codigo;
    std::string nombre;
    double precio_unitario;
    int cantidad;
};

void cargarProductos(std::vector<Producto>& productos) {
    try {
        std::ifstream archivo("productos.txt");
        if (!archivo) {
            throw std::runtime_error("Error al abrir el archivo para cargar.");
        }

        Producto producto;
        while (archivo >> producto.codigo >> producto.nombre >> producto.precio_unitario >> producto.cantidad) {
            productos.push_back(producto);
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}

void guardarProductos(const std::vector<Producto>& productos) {
    try {
        std::ofstream archivo("productos.txt");
        if (!archivo) {
            throw std::runtime_error("Error al abrir el archivo para guardar.");
        }

        for (const auto& producto : productos) {
            archivo << producto.codigo << " "
                    << producto.nombre << " "
                    << producto.precio_unitario << " "
                    << producto.cantidad << "\n";
        }
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}

void ingresarProducto(std::vector<Producto>& productos) {
    Producto producto;
    std::cout << "\t> Ingrese el codigo del producto: ";
    std::cin >> producto.codigo;
    std::cout << "\t> Ingrese el nombre del producto: ";
    std::cin >> producto.nombre;
    std::cout << "\t> Ingrese el precio unitario del producto: ";
    std::cin >> producto.precio_unitario;
    std::cout << "\t> Ingrese la cantidad del producto: ";
    std::cin >> producto.cantidad;
    productos.push_back(producto);

    try {
        std::ofstream archivo("productos.txt", std::ios::app);
        if (!archivo) {
            throw std::runtime_error("Error al abrir el archivo para guardar.");
        }
        archivo << producto.codigo << " "
                << producto.nombre << " "
                << producto.precio_unitario << " "
                << producto.cantidad << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
}

void informacionProducto(const std::vector<Producto>& productos) {
    int codigo;
    std::cout << "Ingrese el codigo del producto: ";
    std::cin >> codigo;
    bool encontrado = false;
    for (const auto& producto : productos) {
        if (producto.codigo == codigo) {
            std::cout << "\t> Codigo: " << producto.codigo << "\n"
                      << "\t> Nombre: " << producto.nombre << "\n"
                      << "\t> Precio unitario: " << producto.precio_unitario << "\n"
                      << "\t> Cantidad: " << producto.cantidad << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cerr << "Producto no encontrado.\n";
    }
}

void informacionTodosProductos(const std::vector<Producto>& productos) {
    for (const auto& producto : productos) {
        std::cout << "\t> Codigo: " << producto.codigo << "\n"
                  << "\t> Nombre: " << producto.nombre << "\n"
                  << "\t> Precio unitario: " << producto.precio_unitario << "\n"
                  << "\t> Cantidad: " << producto.cantidad << "\n";
    }
}

void actualizarProducto(std::vector<Producto>& productos) {
    int codigo;
    std::cout << "\t> Ingrese el codigo del producto a actualizar: ";
    std::cin >> codigo;
    bool encontrado = false;
    for (auto& producto : productos) {
        if (producto.codigo == codigo) {
            std::cout << "\t> Actualizar nombre: ";
            std::cin >> producto.nombre;
            std::cout << "\t> Actualizar precio unitario: ";
            std::cin >> producto.precio_unitario;
            std::cout << "\t> Actualizar cantidad: ";
            std::cin >> producto.cantidad;
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        guardarProductos(productos);
    } else {
        std::cerr << "Producto no encontrado.\n";
    }
}

void actualizarNombre(std::vector<Producto>& productos) {
    int codigo;
    std::cout << "\t> Ingrese el codigo del producto a actualizar: ";
    std::cin >> codigo;
    bool encontrado = false;
    for (auto& producto : productos) {
        if (producto.codigo == codigo) {
            std::cout << "Actualizar nombre: ";
            std::cin >> producto.nombre;
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        guardarProductos(productos);
    } else {
        std::cerr << "Producto no encontrado.\n";
    }
}

void actualizarPrecioUnitario(std::vector<Producto>& productos) {
    int codigo;
    std::cout << "\t> Ingrese el codigo del producto a actualizar: ";
    std::cin >> codigo;
    bool encontrado = false;
    for (auto& producto : productos) {
        if (producto.codigo == codigo) {
            std::cout << "\t> Actualizar precio unitario: ";
            std::cin >> producto.precio_unitario;
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        guardarProductos(productos);
    } else {
        std::cerr << "Producto no encontrado.\n";
    }
}

void actualizarCantidad(std::vector<Producto>& productos) {
    int codigo;
    std::cout << "\t> Ingrese el codigo del producto a actualizar: ";
    std::cin >> codigo;
    bool encontrado = false;
    for (auto& producto : productos) {
        if (producto.codigo == codigo) {
            std::cout << "\t> Actualizar cantidad: ";
            std::cin >> producto.cantidad;
            encontrado = true;
            break;
        }
    }
    if (encontrado) {
        guardarProductos(productos);
    } else {
        std::cerr << "Producto no encontrado.\n";
    }
}

int main() {
    std::vector<Producto> productos;
    cargarProductos(productos);

    int opcion;
    do {
        std::cout << "[]=========================================================[]\n";
        std::cout << "\t\t\t     MENU\n";
        std::cout << "[]=========================================================[]\n";

        std::cout << "\t[1] Ingresar producto\n";
        std::cout << "\t[2] Informacion de producto\n";
        std::cout << "\t[3] Informacion de todos los productos\n";
        std::cout << "\t[4] Actualizar informacion de un producto\n";
        std::cout << "\t[5] Actualizar nombre\n";
        std::cout << "\t[6] Actualizar precio unitario\n";
        std::cout << "\t[7] Actualizar cantidad\n";
        std::cout << "\t[8] Salir\n";
        std::cout << "\n\t>> Seleccione una opcion: ";
        std::cin >> opcion;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Entrada inválida. Intente de nuevo.\n";
            continue;
        }
        
        
        try {
            std::cout << "[]=========================================================[]\n";

            switch (opcion) {
                case 1:
                    ingresarProducto(productos);
                    break;
                case 2:
                    informacionProducto(productos);
                    break;
                case 3:
                    informacionTodosProductos(productos);
                    break;
                case 4:
                    actualizarProducto(productos);
                    break;
                case 5:
                    actualizarNombre(productos);
                    break;
                case 6:
                    actualizarPrecioUnitario(productos);
                    break;
                case 7:
                    actualizarCantidad(productos);
                    break;
                case 8:
                    std::cout << "Saliendo del programa.\n";
                    break;
                default:
                    std::cerr << "Opcion invalida. Intente de nuevo.\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    } while (opcion != 8);

    return 0;
}

