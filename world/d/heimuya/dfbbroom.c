inherit ROOM;

void create()
{
   set("short", "内厅");
        set("long", @LONG
只见四面墙壁，玲珑剔透，琴剑书画，挂在墙上。锦笼纱罩，金彩
珠光，连地上踏的砖，皆是碧绿凿花，左一架书，右一架屏。四面是雕
空的紫檀板壁。一座大床摆在屋子中央，一个女子正在绣花。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"hy",

]));
    set("objects", ([
"/class/heimuya/dfbb" : 1,
  ]) );

        setup();
        replace_program(ROOM);
}

