// Room: /d/new_taohua/nanpuroom.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����ɲ���Ƥ����ľ��ɡ������������٣����ݺ�ٸ�
һ�����������ڿտյ�������ʮ�Ŵ��������У�������
�������ڴ�ɨ���䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "east" : __DIR__"qianting",
]));

	setup();
	replace_program(ROOM);
}
