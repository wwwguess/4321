inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ï�ܵ����֡����������ݷ���ʧ�˷���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"bamboo",
    "west" :__DIR__"bamboo2",
    "north" :__DIR__"bamboo3",
    "south" :__DIR__"bamboo2",

]));
        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
