
inherit ROOM;

void create()
{
    set("short", "�ϵ��᷿");
	set("long", @LONG
����һ���ϵ��᷿���������С���������һ�����ӣ��������!
����һ�����ٷ���ƽ̨��! ǽ�ϳ��������������⣬������һЩ�黭
��һŨ�����µ�������Ϣ! ͨ���Ǹ�Զ�������Ĺ�����ҹ�޵�һ��
�ϵ��᷿��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"two2",

]));

    set("objects", ([
        __DIR__"npc/tguest" : 1,
    ]) );
	setup();
	replace_program(ROOM);
}
