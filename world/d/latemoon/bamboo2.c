inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ï�ܵ����֡����������ݷ���ʧ�˷���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "east" :__DIR__"bamboo4",
    "west" :__DIR__"bamboo3",
    "north" :__DIR__"bamboo3",
    "south" :__DIR__"bamboo1",

]));
	set("objects", ([
	   "/d/latemoon/obj/fake_bamboo" : 1,
]));
        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
