// void.c (re-created after Elon screwed it up on 07-24-95)

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","������԰");
	set("long",@LONG	
����һ�����Ĵ��!
..
��ãã��, ��һ���������ð��һֻ���, �ݸ���һ�ޡ��ɿڿ��֡�(tm), 
Ȼ��վ��һ�Ժ�а���Ц��. �ֹ���һ��, һֻ���������˹���, һ���ı�
����ֻ��첢��������������ƿ����, ��Ц������ʹ�����ǰ��ʧ��.
��ҡҡͷ, ���ֵط����ǲ�Ҫ��̫�õĺ�.
LONG
	);
	set("exits", ([
		"out" : "/d/snow/inn",
	]) );
	setup();
}

