// dizi.c ��������

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��������", ({ "di zi", "zi"}) );
        set("gender", "����");
        set("age", 30);
        set("long",
                "�����һ������������ӣ��书��ǿ\n");
        set("combat_exp", 100000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 22);
        set("int", 20);
        set("dex", 24);
     
      
            set("max_kee", 500);

  set("eff_qi", 500);
        set("kee", 500);
        set("max_gin", 200);
        set("gin", 200);
        set("force", 500);
        set("max_force", 500);
        set("force_factor", 30);
        set("shen_type", 0);

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);

        set_skill("sword", 100);
       set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
      
     

	setup(); 
        carry_object("/obj/weapon/changjian")->wield();

}

