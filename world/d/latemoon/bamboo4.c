inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ��ï�ܵ����֡����������ݷ���ʧ�˷���
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       "west" :__DIR__"bamboo3",
       "east" :__DIR__"bamboo",
       "north" :__DIR__"bamboo1",
       "south" :__DIR__"bamboo2",

]));
        set("objects", ([
            "/d/latemoon/obj/bamboo" : 1 ,
        ]) );
        set("outdoors", "latemoon");
        setup();
        replace_program(ROOM);
}
