inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ï�ܵ����֡����������ݷ���ʧ�˷���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"bamboo1",
    "west" :__DIR__"bamboo2",
    "north" :__DIR__"bamboo3",
    "south" :__DIR__"sroad4",

]));
        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
