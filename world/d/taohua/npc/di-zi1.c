// dizi.c ��������

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��������", ({ "di zi", "zi"}) );
        set("gender", "����");
        set("age", 20);
        set("long",
                "�����һ������������ӣ��书����\n");
        set("combat_exp", 60000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set("str", 26);
        set("con", 22);
        set("int", 20);
        set("dex", 24);
     
      
        set("max_kee", 400);


        set("eff_qi", 400);
        set("kee", 400);
        set("max_gin", 200);
        set("gin", 200);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 20);
        set("shen_type", 0);

        set_temp("apply/attack",  30);
        set_temp("apply/defense", 30);
	
        set_skill("force", 60); 
	set_skill("unarmed", 60);
        set_skill("sword", 60);
        set_skill("strike", 50);
        set_skill("parry", 60);
        set_skill("dodge", 60);

       

  
        setup();     
	 


}

