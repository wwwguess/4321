//NPC: /u/dwolf/work/npc/xiaohou.c
//by dwolf
//97.11.4

#include <ansi.h> 
inherit NPC;

void create()
{
	set_name(BLK"С��"NOR,({ "xiao hou", "hou", "monkey"}) );
        set("gender", "����" );
        set("age", 5);
        set("long", "����һֻ��Ƥ��С���ӣ�����������ȴϲ��ģ��������\n");
        set("combat_exp", 70);
        set("shen_type", -1);
	set("str", 21);
	set("dex", 11);
	set("con", 31);
	set("int", 11);
        set("attitude", "peaceful");
        setup();
}
