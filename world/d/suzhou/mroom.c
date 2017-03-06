// Room: /d/suzhou/mroom.c
//changed by dwolf
//97.11.4

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED "����ׯ" NOR);
	set("long","��������վ��" + RED "����ׯ" NOR + "�������ר������" + RED "�޽��Լ" NOR + "��" + GRN "�����Լ" NOR + "�ĵط���\n�������еķ򸾶���������" + RED "ϲ����Ե" NOR + "�ģ�������������Ҳ�����Ľ��������\n�����ſڵĵط���һ���ľ��ɵ�" + RED "����" NOR +"(sign)��\n");

        set("exits", ([ 
  		"east" : __DIR__"sroad1",
	]));

        set("item_desc", ([ 
  		"sign" : RED "�޽������Լ��\n" NOR,
	]));

        set("objects", ([ 
 		 __DIR__"npc/meipo" : 1,
	]));

        set("no_clean_up", 0);

        setup();
}

