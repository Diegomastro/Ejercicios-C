/*
 Se dispone de un archivo con las ventas del mes de cada una de las sucursales de una empresa. El archivo
se encuentra ordenado por sucursal y contiene la siguiente estructura:
 Sucursal (15 caracteres máximo)
 Código de producto (entero)
 Cantidad (entero)
Por otro lado se dispone de un archivo de los productos que vende la empresa y el estado del stock al mes
pasado con la siguiente estructura:
 Código de producto (entero)
 Descripción (20 caracteres máximo)
 Precio (float)
 Stock (entero)
 Punto de pedido (entero)
 Cantidad para pedido (entero)
No se sabe la cantidad exacta de productos pero sí se sabe que no hay más de 200.
Se desea:
1) Mostrar el importe total vendido en cada sucursal.
2) Mostrar la recaudación total de la empresa en el mes.
3) Determinar la sucursal que vendió mayor cantidad de productos.
4) Actualizar el archivo de productos con el nuevo stock.
5) Realizar un archivo llamado pedidos.dat que incluya aquellos productos que deben solicitarse
(código y cantidad) de aquellos productos que al finalizar de procesar las ventas del mesa queden
con stock menor al punto de pedido.
*/

#include <stdio.h>
#include <string.h>

struct Venta
{
    char suc[16];
    int cod;
    int cant;
};

struct Producto
{
    int cod;
    char desc[21];
    float precio;
    int stock;
    int punto_ped;
    int cant_ped;
};

struct Pedido
{
    int cod;
    int cant;
};

void cargar_productos(struct Producto productos[])
{
    FILE* f_productos = fopen("productos.dat", "rb");
    int i = 0;
    while (!feof(productos.dat))
    {
        fread(productos[i], sizeof(struct Producto), 1, f_productos);
        i++;
    }
    productos[i].cod = -1
    fclose(f_productos);
}
   
int buscar_producto(int cod, struct Producto productos[])
{
    int i = 0;
    for (i = 0; i < 200; i++)
    {
        if (productos[i].cod == cod)
        {
            return i;
        }
    }
}

void actualizar(struct Producto productos[] ,FILE* f_ventas)
{
    int i;
    while(productos[i] != -1)
    {
        fwrite(productos[i], sizeof(struct Producto), 1, f_ventas);
        i++;
    }
}

void armar_pedidos(struct Producto productos[])
{
    FILE* f_pedidos = fopen("pedidos.dat", "wb");
    int i = 0;
    while (productos[i] != -1)
    {
        if (productos[i].stock < productos[i].punto_ped)
        {
            fwrite(productos[i], sizeof(struct Producto), 1, f_pedidos);
        }
        i++;
    }
    fclose(f_pedidos);
}

int main()
{
    char suc_vendiomas[16];
    char suc_ant[16];
    int suc_vendidos;
    int cant_vendiomas;
    int primera = 1;
    int pos;
    FILE* f_ventas;
    float suc_total;
    float total = 0;
    struct Venta venta;
    struct Pedido pedido;
    struct Producto producto;
    struct Producto productos[200];

    f_ventas = fopen("ventas.dat", "rb");
    cargar_productos(productos);

    fread(venta, sizeof(struct Venta), 1, f_ventas);

    while (!feof(f_ventas))
    {
        strcpy(suc_ant, venta.suc);
        suc_total = 0;
        suc_vendidos = 0;

    }

    while (!feof(f_ventas) && !strcmpi(suc_ant, venta.suc))
    {
        pos = buscar_producto(venta.cod ,productos);
        suc_total += productos[pos].precio * productos[pos].cant;
        suc_vendidos += productos[pos].cant;
        productos[pos].stock -= venta.cant
        fread(venta, sizeof(struct Venta), 1, f_ventas);
    }
    total += suc_total;
    printf("TOTAL %s: $%.2f \n", suc_ant, suc_total);
    if (suc_vendidos < cant_vendiomas || primera)
    {
        strcpy(suc_vendiomas, suc_ant);
        cant_vendiomas = suc_vendidos;
        primera = 0;
    }
    printf("TOTAL: $%.2f\n", total);
    printf("SUCURSAL QUE MAS VENDIO FUE %s \n", suc_vendiomas);
    actualizar(productos, f_ventas);
    armar_pedidos(productos);
    fclose(f_ventas);
    fclose(f_productos);
    return 0;
}
