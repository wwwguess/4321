// Mon  08-21-95

inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
����һ���ª����լ������խС������ɢ��һ�صĲ��͸�ʽ���ߡ�
�ݽǵ�ʯ¯������΢���Ļ�⣬һ����֪��ʲô�Ķ�����ð��������ζ��
��һ�Ƿ���һ�ż�ª��ľ���ͼ������ӡ�
 
LONG
	);
    set("exits", ([
    "east" : __DIR__"path3",
]));
	set("objects", ([
    __DIR__"npc/woman1" : 1,
    __DIR__"npc/woman2" : 1,
		]) );

	setup();
	replace_program(ROOM);
}
