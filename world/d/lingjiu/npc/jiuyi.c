// NPC jiuyi.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�������", ({ "jiuyi daoren", "jiuyi"}));
	set("long",
	    "��������һƷ����Ƹ�ĸ���,��ĸ���,����������������,\n"+
	    "���Ṧ����,��ʹ�׹���,ƾһ���׹�������,��Ϊ������һ������.\n");
	set("title", "����һƷ�ø���");
	set("gender", "����");
	set("nickname", HIR "�׶��ھ���֮��" NOR);
	set("age", 40);
	set("shen_type",-1);
	set("attitude", "peaceful");

	set("str", 27);
	set("int", 23);
	set("con", 24);
	set("dex", 30);

	
	set("max_kee", 1000);
 	set("kee", 1000);
	set("gin", 500);
	set("max_gin", 500);
	set("force", 1000);
	set("max_force", 1000);
	set("jiali", 0);

	set("combat_exp", 1000000);
	set("score", 100000);
	setup();
}