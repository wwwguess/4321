// xkx npc cave1 npc2.c  
//dan
inherit NPC;
void consider();
void create()
{
    set_name("���ʺ�", ({"wen renhou", "wen"}));
    set("nickname", "ɽ�����ɽ�����");
    set("gender", "����");
    set("age", 60);
    set("long", 
      "�����ڿ���ǽ����˼.\n");
    set("attitude", "peaceful");
     

    setup();
    carry_object("/obj/weapon/changjian")->wield();
    carry_object("/d/wudang/obj/whiterobe")->wear();
}






