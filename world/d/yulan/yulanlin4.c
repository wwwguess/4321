inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
����һƬï�ܵ��������֡�����������ݷ���ʧ�˷���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       "west" :__DIR__"yulanlin3",
       "east" :__DIR__"yulanlin",
       "north" :__DIR__"yulanlin1",
       "south" :__DIR__"yulanlin2",

]));
        set("objects", ([
            "/d/yulan/npc/butterfly" : 1 ,
        ]) );
        set("outdoors", "yulan");
        setup();
        replace_program(ROOM);
}
