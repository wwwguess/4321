inherit ROOM;

void create()
{
        set("short", "����С��"),
        set("long", @LONG
�������������ѵ�С����, �������ߵ�С����һ���ͱڵ�ס��,
���С���������򶫱�ȥ, �����������һƬ�Ӳݺͼ���С����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
          "northwest" :__DIR__"sroad1",
          "east" :__DIR__"sroad3",
]));

        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
