// dizi.c ��������

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��������", ({ "di zi", "zi"}) );
        set("gender", "����");
        set("age", 25);
        set("long",
                "�����һ������������ӣ��书��ǿ\n");
        set("combat_exp", 80000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 22);
        set("int", 20);
        set("dex", 24);
     
      
        set("max_kee", 450);


      set("eff_qi", 450);
        set("kee", 450);
        set("max_gin", 200);
        set("gin", 200);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 25);
        set("shen_type", 0);

        set_temp("apply/attack",  40);
        set_temp("apply/defense", 40);

        set_skill("sword", 80);
        set_skill("force", 80);
        set_skill("hand", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);
     
                     
        setup();     
	 
        carry_object("/obj/weapon/changjian")->wield();

}

