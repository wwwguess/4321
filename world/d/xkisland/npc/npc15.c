// xkx npc cave12-23 npc15.c 
//dan
inherit NPC;
void consider();
void create()
{
    set_name("��������", ({"ke"}));
    set("gender", "����");
    set("age", 100);
    set("long", 
      "��˫Ŀ�̺���⣬�书��ɲ�.\n");
    set("attitude", "peaceful");
     

    setup();
    carry_object("/obj/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}





