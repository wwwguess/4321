inherit ROOM;

void create()
{
    set("short","小院");
        set("long", @LONG
这是玉兰山庄後的小小庭院，面积似乎不大，但花木扶疏，举目四望，
竟种满了无数玉兰花，婉约娟秀，别有一番滋味。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "west" :__DIR__"yulanc",

]));

        setup();
        replace_program(ROOM);
}
