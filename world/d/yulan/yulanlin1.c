inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
����һƬï�ܵ��������֡�����������ݷ���ʧ�˷���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"yulanlin",
    "west" :__DIR__"yulanlin2",
    "north" :__DIR__"yulanlin3",
    "south" :__DIR__"yulanlin2",

]));
        set("outdoors", "yulan");
        setup();
        replace_program(ROOM);
}
