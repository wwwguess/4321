//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"��Ҵ�Ժ"NOR);
	set("long", @LONG
���߽���Ժ��ӭ����һ�����磬�����ϻ���һЩ������԰������˵�ǵ���
��ʩ�ù��Ķ�������������Ǽ�ɽ��ɽ���и�ˮ�أ�ˮ�����и���Ȫ��ˮ��
��ɢ��ʮ�ֺÿ���԰�Ӷ��ϱ���һЩ���ݣ�һ��԰�����ڹ�����
LONG
	);
	set("exits", ([
		"east" : __DIR__"zuojia",
		"southwest" : __DIR__"zuojia3",
]));                                      
	set("objects", ([
		__DIR__"npc/yuanding" : 1,
]));
	setup();
	replace_program(ROOM);
}
