inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������һ�����ѵ�С��, С���������ǰ���˸ߵ��Ӳ�, ����Ը���
��������΢������വ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
         "southeast" :__DIR__"sroad2",
         "north" : "/d/sanyen/gate",
]));
        set("outdoors", "latemoon");

        setup();
        replace_program(ROOM);
}
