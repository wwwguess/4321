// Room: /d/new_taohua/fmfroom.c

inherit ROOM;

void create()
{
	set("short", "��Ĭ���");
	set("long", @LONG
�����Ƿ�Ĭ��ľ��������ڷ�Ĭ���ڵ�����ͽ������
�����ˣ�����ҩʦ���ǰ����Ӹ������š�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "north" : __DIR__"yonglu6",
  
]));
	

	setup();
	replace_program(ROOM);
}
