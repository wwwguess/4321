// /d/emei/yunvfeng.c ������ ��Ů��

inherit ROOM;

void create()
{
	set("short", "��Ů��");
	set("long", @LONG
�����ǻ�ɽ���з壬��Ů�塣��Ů�������Ϊƽ�������������ķ��
�վ��������Ϻպ������Ļ�ɽ���ɾ��ڴ˴�����������СС������Ǿ�
����Ů���ˡ�������ϡϡ������ʮ���䷿�ӣ��ǻ�ɽ�ɵĵط��������ο�
��ñ�������ȥ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"northdown" : __DIR__"guanyintang",
		]));
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("objects", ([ 
		__DIR__"npc/lingshan" : 1,
	]));

	setup();
	replace_program(ROOM);
}