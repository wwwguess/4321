//yingkaishan.c
//created by kiss
#include <ansi.h>
inherit NPC;
void create()
{
      set_name(HIB"��ɽ"NOR, ({"yin kanshan","yin"}));
      set("nickname", RED"�����ܹ�"NOR);
      set("gender","����");
      set("age",40);
      set("long",@LONG
�����ǵ����ܹܣ�����Ŀ����,
LONG
    );
       set("attitude","peaceful");
       set("str",30);
       set("int",50);
       set("con",25);
       set("combat_exp",200000000);
       set("force",1000);
       set("max_force",20000);
       set("force_factor",40);
       set_skill("dodge",500);
       set_skill("parry",500);
       set_skill("sword",500);
       set_skill("unarmed",500);
       set_skill("force",300);
       set("chat_chance",20);
       set("chat_msg",({
      HIM"��ɽ˵������С�ֵܵ������������кι�ɰ�����\n"NOR,
    }));
     setup();
     carry_object("/d/jingcheng/npc/obj/cloth2")->wear();
     carry_object("/d/jingcheng/npc/obj/changjian")->wield();
}
int accept_fight(object ob)
{   
      command("say ����Ժ�Ϊ�󣬺α��ո������һ��أ�");
      command("sigh");
      command("kick"+ob->query("id"));
     return 0;
}
 
   

