//ROOM: /d/shanzhuang/qyuan.c
//by dwolf
//97.11.5

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ǰԺ");
	set("long", "����ɽׯ��ǰԺ�����˸����滨��ݣ���������÷����ֵ���
�������÷һ�굽ͷ�ܿ��š�Ժ�������������������졣���Ǵ��ú��ƣ�������ȥȴ��
���֡����Ǻ���������ʲô��\n");  
	set("exits", ([
		"south" : "/u/dwolf/test/door.c",
		"north" : "/u/dwolf/test/ting.c",
		"west" : "/u/dwolf/test/kefan1.c",
		"east" : "/u/dwolf/test/kefan2.c",  
	])); 
	set("objects", ([
		"/u/dwolf/test/npc/zuo.c" : 1,
		"/u/dwolf/test/npc/wang.c" : 1,
]));	
	setup();
	replace_program(ROOM);
}
