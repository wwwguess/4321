// Room: /d/jingcheng/xjqzh.c
// Made by: ysgl

#include <ansi.h>
inherit BANK;

void create()
{
	set("short", "[1;37m���Ǯׯ[2;37;0m");
	set("long", @LONG
����һ�����ֺŵ�Ǯׯ�����ϰ���ɽ���ˣ����Ǯׯ������үү��
үү��үү��үү�Ǳ���ʼ����һֱ��������������ǳ��ã�
��ȫ�����ض��зֵꡣ�����е���Ʊͨ��ȫ����Ǯׯ���ſڹ���һ
������(paizi)��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"xchjie5",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/banker" : 1,
]));
	set("item_desc", ([
	"paizi" : "��ׯ�ɻ�Ǯ����Ǯ��ȡǮ����������.\n
                   cun <����> <��������>\n
                   qu <����> (unit: coin)\n
                   check ���� \n 
                   convert <����> <��������> to <��������>\n  ",
]));

	setup();
}
