// Room: /d/new_taohua/nanpuroom.c
//write by lysh
inherit ROOM;

void create()
{
	set("short", "Ů������");
	set("long", @LONG
�����ɲ���Ƥ����ľ��ɡ������������٣����ݺ�ٸ�
һ�����������ڿտյ�������ʮ�Ŵ��������У�����Ů
�������ڴ�ɨ���䡣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */  
  "west" : __DIR__"qianting",
]));

	setup();
	replace_program(ROOM);
}
