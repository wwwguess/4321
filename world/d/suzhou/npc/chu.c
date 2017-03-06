//NPC:/d/suzhou/npc/chu.c  
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "wanyan liang", "wanyan" }));
        set("title",CYN "��ʹ" NOR);
	set("gender", "����");
	set("age", 33);
	set("str", 40);
	set("dex", 30);
	set("per", 37);
	set("int",70);
	set("long", @LONG
	  �����ǽ����ɵ���ԭ����ʹ����������ѣ�����Ǵ���΢Ц��һ���������ص����ӡ�
LONG
	);
	set("combat_exp", 500000);
	set("shen_type", 20);
	set("attitude", "heroism");

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("dodge", 150);
	set_skill("parry", 100);
	set_skill("leadership", 150);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 75);

	set("force", 800); 
	set("max_force", 800);
	set("force_factor", 30);

	setup();
	carry_object(__DIR__"obj/blade")->wield();  
	carry_object(__DIR__"obj/zhuyeq");
}

