inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
�������ѵ�С��ͨ�����Ϸ�, ����Ķ�����һ������, �������
������һ��ï�ܵ����֡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
           "northwest" :__DIR__"sroad3",
           "west" :__DIR__"bamboo1",
           "south" :__DIR__"sroad4",

]));

        set("objects", ([
           "/d/latemoon/npc/butterfly" : 1 ]) );
        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
