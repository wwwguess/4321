// guard2.c
//by dwolf

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(GRN"��Ժ"NOR, ({ "hu yuan", "guard" }) );
      	set("long", "��˵�����Ժ�����ֵĸ��֣��书����\n"); 

        set("attitude", "peaceful");

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

	set("combat_exp", 50000);

        set("chat_chance", 2);
	set("chat_msg", ({
        	"��Ժ�૵���С����ô��û����Ϣ����\n",
	}) );

        set_skill("unarmed", 90);
        set_skill("parry", 60);
	set_skill("dodge", 90);

        setup();
    /*    carry_object("/d/suzhou/npc/obj/cloth")->wear();  */
}

	     
		
